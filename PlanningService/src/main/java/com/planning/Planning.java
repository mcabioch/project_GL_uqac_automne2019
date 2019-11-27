package com.planning;

import org.bson.types.ObjectId;
import org.springframework.data.annotation.Id;
import org.springframework.data.mongodb.core.mapping.Document;

@Document(collection = "planning")
public class Planning {
	
	@Id
	private ObjectId id;
	private ObjectId user_id;
	private ObjectId team_id;
	private String jour_de_repos;
	private int nb_heures;

	
	public Planning(ObjectId id, ObjectId user_id, ObjectId team_id, String jour_de_repos, int nb_heures) {
		this.setId(id);
		this.setUser_id(user_id);
		this.setTeam_id(team_id);
		this.setJour_de_repos(jour_de_repos);
		this.setNb_heures(nb_heures);
		
	}
	
	public String getId() {return id.toHexString();}
	public ObjectId getObjectId() {return id;}
	
	public void setId(ObjectId id) { this.id = id; }
	
	public ObjectId getUser_id() {
		return user_id;
	}

	public void setUser_id(ObjectId user_id) {
		this.user_id = user_id;
	}

	public ObjectId getTeam_id() {
		return team_id;
	}

	public void setTeam_id(ObjectId team_id) {
		this.team_id = team_id;
	}

	public String getJour_de_repos() {
		return jour_de_repos;
	}

	public void setJour_de_repos(String jour_de_repos) {
		this.jour_de_repos = jour_de_repos;
	}

	public int getNb_heures() {
		return nb_heures;
	}

	public void setNb_heures(int nb_heures) {
		this.nb_heures = nb_heures;
	}
}
