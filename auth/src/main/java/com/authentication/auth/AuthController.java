package com.authentication.auth;

import java.math.BigInteger;
import java.nio.charset.StandardCharsets;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Base64;
import java.util.HashMap;
import java.util.Map;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestHeader;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class AuthController {
	@Autowired
	private UserRepository userRepository;
	
	private MessageDigest md;
	
	public static String toHexString(byte[] hash) 
    { 
        // Convert byte array into signum representation  
        BigInteger number = new BigInteger(1, hash);  
  
        // Convert message digest into hex value  
        StringBuilder hexString = new StringBuilder(number.toString(16));  
  
        // Pad with leading zeros 
        while (hexString.length() < 32)  
        {  
            hexString.insert(0, '0');  
        }  
  
        return hexString.toString();  
    }

	@GetMapping("/auth")
	public Map<String, String> generateToken(@RequestHeader("Authorization") String auth) {
		
		String token = auth.split(" ")[1];
		byte[] decodedBytes = Base64.getDecoder().decode(token);
		String username = new String(decodedBytes).split(":")[0];
		
		User u = userRepository.findByUsername(username);
		
		try {
			md = MessageDigest.getInstance("SHA-256");
		} catch (NoSuchAlgorithmException e) {
			e.printStackTrace();
		}
		
		String encodedHash = toHexString(md.digest(u.getPassword().getBytes(StandardCharsets.UTF_8)));
		
		return new HashMap<String, String>() {
			private static final long serialVersionUID = -4977786689717466828L;
			{
				put("userId", u.getId());
				put("token", encodedHash);
			}
		};
	}
}