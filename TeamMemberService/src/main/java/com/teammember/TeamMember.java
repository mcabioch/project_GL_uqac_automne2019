package com.teammember;

import org.bson.types.ObjectId;
import org.springframework.data.annotation.Id;
import org.springframework.data.mongodb.core.mapping.Document;

@Document(collection = "team_member")
public class TeamMember {
	
	@Id
	private ObjectId id;
	private ObjectId userId;
	private ObjectId teamId;
	private String jourDeRepos;
	private int nbHeures;

	public TeamMember(ObjectId id, ObjectId userId, ObjectId teamId, String jourDeRepos, int nbHeures) {
		this.setId(id);
		this.setUserId(userId);
		this.setTeamId(teamId);
		this.setJourDeRepos(jourDeRepos);
		this.setNbHeures(nbHeures);
	}
	
	public String getId() {return id.toHexString();}
	
	public void setId(ObjectId id) { this.id = id; }
	
	public String getUserId() {
		return userId.toHexString();
	}

	public void setUserId(ObjectId user_id) {
		this.userId = user_id;
	}
	
	public String getTeamId() {
		return teamId.toHexString();
	}

	public void setTeamId(ObjectId team_id) {
		this.teamId = team_id;
	}

	public String getJourDeRepos() {
		return jourDeRepos;
	}

	public void setJourDeRepos(String jour_de_repos) {
		this.jourDeRepos = jour_de_repos;
	}

	public int getNbHeures() {
		return nbHeures;
	}

	public void setNbHeures(int nbHeures) {
		this.nbHeures = nbHeures;
	}
}
