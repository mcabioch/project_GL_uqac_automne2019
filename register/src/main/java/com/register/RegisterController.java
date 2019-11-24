package com.register;

import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.List;

import javax.validation.Valid;

import org.apache.http.NameValuePair;
import org.apache.http.client.entity.UrlEncodedFormEntity;
import org.apache.http.client.methods.CloseableHttpResponse;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.impl.client.CloseableHttpClient;
import org.apache.http.impl.client.HttpClients;
import org.apache.http.message.BasicNameValuePair;
import org.apache.http.util.EntityUtils;
import org.bson.types.ObjectId;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class RegisterController {
	
	@Autowired
	private UserRepository userRepository;
	
	private BCryptPasswordEncoder bCrypt = new BCryptPasswordEncoder();
	
	public boolean verify(String username, String token) {
		HttpPost request = new HttpPost("http://localhost:8081/verify");
		
		List<NameValuePair> urlParams = new ArrayList<>();
		urlParams.add(new BasicNameValuePair("username",username));
		urlParams.add(new BasicNameValuePair("token",token));
		
		try {
			request.setEntity(new UrlEncodedFormEntity(urlParams));
		} catch (UnsupportedEncodingException e) {
			e.printStackTrace();
		}
		
		CloseableHttpClient httpClient = HttpClients.createDefault();
		
		try {
			CloseableHttpResponse response = httpClient.execute(request);
			System.out.println(EntityUtils.toString(response.getEntity()));
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		return false;
	}

	@PostMapping("/create")
	public String createUser(@Valid @RequestBody User user) {
		user.setId(ObjectId.get());
		user.setPassword(bCrypt.encode(user.getPassword()));
		userRepository.save(user);
		return user.getId();
	}
}