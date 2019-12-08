package com.user;

import java.util.List;

import org.bson.types.ObjectId;
import org.json.JSONObject;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.security.core.userdetails.UsernameNotFoundException;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PatchMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class UserController {
	
	@Autowired
	private UserRepository userRepository;
	
	// Get a user given his is id
	@GetMapping("/users/{id}")
	public ResponseEntity<Object> getUserById(@PathVariable String id) {
		if(!ObjectId.isValid(id)) return new ResponseEntity<>("Invalid user id", HttpStatus.BAD_REQUEST);
		
		ObjectId _id = new ObjectId(id);
		User user = userRepository.findById(_id);
		
		if(user == null) throw new UsernameNotFoundException("User not found");
		
		return new ResponseEntity<>(user, HttpStatus.OK);
	}
	
	// Get all users
	@GetMapping("/users")
	public List<User> getUsers() {
		return userRepository.findAll();
	}
	
	@PatchMapping("/user/{id}/edit")
	public ResponseEntity<Object> editUserById(@RequestBody String body, @PathVariable String id) {
		JSONObject userJson = new JSONObject(body);
		
		if(!ObjectId.isValid(id)) {
			return new ResponseEntity<>("Invalid userId", HttpStatus.BAD_REQUEST);
		}
		
		if(!(getUserById(id).getStatusCode() == HttpStatus.OK)) {
			return new ResponseEntity<>("User not found", HttpStatus.NOT_FOUND);
		} else {
			User dbUser = (User) getUserById(id).getBody();
			
			if(userJson.has("name")) dbUser.setName(userJson.getString("name"));
			if(userJson.has("surname")) dbUser.setSurname(userJson.getString("surname"));

			
			userRepository.save(dbUser);
			
			dbUser = (User) getUserById(id).getBody();
			
			return new ResponseEntity<>(dbUser, HttpStatus.OK);
		}
	}
	
	// Delete a user
	@DeleteMapping("/user/{id}/delete")
	public String deleteUsers(@PathVariable String id) {
		User user = (User) getUserById(id).getBody();

		return "Deleted " + userRepository.deleteUserById(new ObjectId(user.getId())) + " items";
	}
}