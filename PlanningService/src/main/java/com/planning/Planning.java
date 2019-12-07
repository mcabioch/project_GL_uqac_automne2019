package com.planning;

import java.util.Map;

import org.bson.types.ObjectId;
import org.springframework.data.annotation.Id;
import org.springframework.data.mongodb.core.mapping.Document;

@Document(collection = "planning")
public class Planning {
	
	@Id
	private ObjectId id;
	private ObjectId userId;
	private Map<String, String> creneau;
	private String date;

	public Planning(ObjectId id, ObjectId userId, Map<String, String> creneau, String date) {
		this.setId(id);
		this.setUserId(userId);
		this.setCreneau(creneau);
		this.setDate(date);
	}
	
	public String getId() {return id.toHexString();}
	public ObjectId getObjectId() {return id;}
	
	public void setId(ObjectId id) { this.id = id; }
	
	public String getUserId() {
		return userId.toHexString();
	}

	public void setUserId(ObjectId user_id) {
		this.userId = user_id;
	}

	public Map<String, String> getCreneau() {
		return creneau;
	}

	public void setCreneau(Map<String, String> creneau) {
		this.creneau = creneau;
	}

	public String getDate() {
		return date;
	}

	public void setDate(String date) {
		this.date = date;
	}
}
