package com.register;

import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.List;

import org.apache.http.NameValuePair;
import org.apache.http.client.entity.UrlEncodedFormEntity;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.impl.client.CloseableHttpClient;
import org.apache.http.impl.client.HttpClients;
import org.apache.http.message.BasicNameValuePair;
import org.bson.types.ObjectId;
import org.json.JSONObject;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class RegisterController {
	
	@Autowired
	private UserRepository userRepository;
	
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
			httpClient.execute(request);
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		return false;
	}

	@PostMapping("/create")
	public User createUser(@RequestBody String body) {
		JSONObject userJson = new JSONObject(body);
	
		User user = new User(
			ObjectId.get(),
			userJson.get("username").toString(),
			userJson.get("password").toString(),
			userJson.get("name").toString(),
			userJson.get("surname").toString()
		);
		
		userRepository.save(user);
		return user;
	}
}