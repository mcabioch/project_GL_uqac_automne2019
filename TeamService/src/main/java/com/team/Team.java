package com.team;

import java.util.Map;

import org.bson.types.ObjectId;
import org.springframework.data.annotation.Id;
import org.springframework.data.mongodb.core.mapping.Document;

@Document(collection = "team")
public class Team {
	
	@Id
	private ObjectId id;
	private int defaultHeures;
	private String nonTravail;
	private Map<String, String> creneau;
	private ObjectId chefId;

	public Team(ObjectId id, int defaultHeures, String nonTravail, Map<String, String> creneau, ObjectId chefId) {
		this.setId(id);
		this.setDefaultHeures(defaultHeures);
		this.setNonTravail(nonTravail);
		this.setCreneau(creneau);
		this.setChefId(chefId);
	}
	
	public String getId() {return id.toHexString();}
	//public ObjectId getObjectId() {return id;}
	
	public void setId(ObjectId id) { this.id = id; }

	public int getDefaultHeures() {
		return defaultHeures;
	}

	public void setDefaultHeures(int defaultHeures) {
		this.defaultHeures = defaultHeures;
	}

	public String getNonTravail() {
		return nonTravail;
	}

	public void setNonTravail(String nonTravail) {
		this.nonTravail = nonTravail;
	}

	public Map<String, String> getCreneau() {
		return creneau;
	}

	public void setCreneau(Map<String, String> creneau) {
		this.creneau = creneau;
	}

	public String getChefId() {
		return chefId.toHexString();
	}

	public void setChefId(ObjectId chef_id) {
		this.chefId = chef_id;
	}
	
}
