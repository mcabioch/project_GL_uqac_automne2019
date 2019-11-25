package com.team;


import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

import org.apache.http.client.methods.CloseableHttpResponse;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.CloseableHttpClient;
import org.apache.http.impl.client.HttpClients;
import org.apache.http.util.EntityUtils;
import org.bson.types.ObjectId;
import org.json.JSONObject;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class TeamController {
	
	@Autowired
	private TeamRepository teamRepository;
	
	public boolean checkIfExists(ObjectId userId) {
		HttpGet request = new HttpGet("http://localhost:8083/users/"+userId.toHexString());		
		CloseableHttpClient httpClient = HttpClients.createDefault();
		
		try {
			CloseableHttpResponse response = httpClient.execute(request);
			if(EntityUtils.toString(response.getEntity()).contains("username")) return true;
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		return false;
	}
	
	@GetMapping("/team/{id}")
	public Team getTeamById(@PathVariable String id) {		
		if(!ObjectId.isValid(id)) return null;
		
		ObjectId _id = new ObjectId(id);
		Team team = teamRepository.findById(_id);

		if(team == null) return null;
		
		return team;
	}
	
	@PostMapping("/create")
	private ResponseEntity<Object> createTeam(@RequestBody String body) {
		JSONObject teamJson = new JSONObject(body);
		
		if(!ObjectId.isValid(teamJson.getString("chefId"))) {
			return new ResponseEntity<>("Invalid chefId", HttpStatus.BAD_REQUEST);
		} 
		
		ObjectId chefId = new ObjectId(teamJson.getString("chefId"));
		
		if(!checkIfExists(chefId)) {
			return new ResponseEntity<>("Chef not found", HttpStatus.NOT_FOUND);
		}
		
		Map<String, String> creneau = new HashMap<String,String>() {
			private static final long serialVersionUID = 1L;
			{
				put("debut", teamJson.getString("creneauDebut"));
				put("fin", teamJson.getString("creneauFin"));
			}
		};
		
		Team team = new Team(
			ObjectId.get(),
			teamJson.getInt("defaultHeures"),
			teamJson.getString("nonTravail"),
			creneau,
			chefId
		);
		
		team.setId(ObjectId.get());
		teamRepository.save(team);
		
		return new ResponseEntity<>(team, HttpStatus.CREATED);
	}
	
	@DeleteMapping("/team/{id}/delete")
	private ResponseEntity<String> deleteTeam(@PathVariable String id) {
		Team tm = getTeamById(id);
		
		if(tm == null) return new ResponseEntity<>("Team not found", HttpStatus.NOT_FOUND);
		
		return new ResponseEntity<>("Deleted " + teamRepository.deleteTeamById(new ObjectId(tm.getId())) + " items", HttpStatus.OK);
	}
}