package com.user;

import java.util.List;

import org.bson.types.ObjectId;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.core.userdetails.UsernameNotFoundException;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class UserController {
	
	@Autowired
	private UserRepository userRepository;
	
	@GetMapping("/users/{id}")
	public User getUserById(@PathVariable String id) {
		if(!ObjectId.isValid(id)) throw new UsernameNotFoundException("User not found");
		ObjectId _id = new ObjectId(id);
		User user = userRepository.findById(_id);
		
		if(user == null) throw new UsernameNotFoundException("User not found");
		
		return user;
	}
	
	@GetMapping("/users")
	public List<User> getUsers() {
		return userRepository.findAll();
	}
	
	@DeleteMapping("/user/{id}/delete")
	public String deleteUsers(@PathVariable String id) {
		User user = getUserById(id);

		return "Deleted " + userRepository.deleteUserById(user.getObjectId()) + " items";
	}
}