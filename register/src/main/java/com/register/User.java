package com.register;

import org.bson.types.ObjectId;
import org.springframework.data.annotation.Id;
import org.springframework.data.mongodb.core.mapping.Document;

@Document(collection = "users")
public class User {
	
	@Id
	private ObjectId id;
	private String username;
	private String password;

	
	public User(ObjectId id, String username, String password) {
		this.id = id;
		this.username = username;
		this.password = password;
	}
	
	public String getId() {return id.toHexString();}
	
	public void setId(ObjectId id) { this.id = id; }
	
	public String getUsername() {return username;}
	
	public void setUsername(String username) {this.username = username;}

    public String getPassword() {return password;}

    public void setPassword(String password) {this.password = password;}
}
