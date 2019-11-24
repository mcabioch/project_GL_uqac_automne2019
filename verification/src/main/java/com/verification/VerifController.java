package com.verification;

import java.math.BigInteger;
import java.nio.charset.StandardCharsets;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

import org.bson.types.ObjectId;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.core.userdetails.UsernameNotFoundException;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class VerifController {
	
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
	
	@PostMapping("/verify")
	public boolean checkToken(@RequestBody UserToken uTok) {
		User u = userRepository.findById(new ObjectId(uTok.id));
		
		if(u == null) {
			throw new UsernameNotFoundException("User not found");
		}
		
		try {
			md = MessageDigest.getInstance("SHA-256");
		} catch (NoSuchAlgorithmException e) {
			e.printStackTrace();
		}
		
		String encodedHash = toHexString(md.digest(u.getPassword().getBytes(StandardCharsets.UTF_8)));
		
		if(uTok.token.equals(encodedHash)) {
			return true;
		} else {
			return false;
		}
	}
}