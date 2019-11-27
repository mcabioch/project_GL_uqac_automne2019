package com.teammember;


import java.io.IOException;
import java.util.List;

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
public class TeamMemberController {
	
	@Autowired
	private TeamMemberRepository teamMemberRepository;
	
	public boolean checkIfUserExists(ObjectId userId) {
		HttpGet request = new HttpGet("http://localhost:8083/users/" + userId.toHexString());		
		CloseableHttpClient httpClient = HttpClients.createDefault();
		
		try {
			CloseableHttpResponse response = httpClient.execute(request);
			if(EntityUtils.toString(response.getEntity()).contains("username")) return true;
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		return false;
	}
	
	public boolean checkIfTeamExists(ObjectId teamId) {
		HttpGet request = new HttpGet("http://localhost:8085/team/" + teamId.toHexString());		
		CloseableHttpClient httpClient = HttpClients.createDefault();
		
		try {
			CloseableHttpResponse response = httpClient.execute(request);
			if(EntityUtils.toString(response.getEntity()).contains("chefId")) return true;
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		return false;
	}
	
	@GetMapping("/teamMember/{id}")
	public TeamMember getTeamMemberById(@PathVariable String id) {		
		if(!ObjectId.isValid(id)) return null;
		System.out.println("ICI");
		ObjectId _id = new ObjectId(id);
		TeamMember teamMember = teamMemberRepository.findById(_id);

		if(teamMember == null) return null;
		
		return teamMember;
	}

	@GetMapping("/teamMember/user/{id}")
	public TeamMember getTeamMemberByUserId(@PathVariable String id) {		
		if(!ObjectId.isValid(id)) return null;
		ObjectId _id = new ObjectId(id);
		
		TeamMember teamMember = teamMemberRepository.findByUserId(_id);
		
		if(teamMember == null) return null;
		
		return teamMember;
	}
	
	@GetMapping("/teamMember/team/{id}")
	public List<TeamMember> getTeamMemberByTeamId(@PathVariable String id) {		
		if(!ObjectId.isValid(id)) return null;
		ObjectId _id = new ObjectId(id);
		
		List<TeamMember> teamMembers = teamMemberRepository.findByTeamId(_id);
		

		if(teamMembers == null) return null;
		
		return teamMembers;
	}
	
	@PostMapping("/create")
	private ResponseEntity<Object> createTeamMember(@RequestBody String body) {
		JSONObject teamMemberJson = new JSONObject(body);
		
		if(!ObjectId.isValid(teamMemberJson.getString("userId"))) {
			return new ResponseEntity<>("Invalid userId", HttpStatus.BAD_REQUEST);
		} else if (!ObjectId.isValid(teamMemberJson.getString("teamId"))) {
			return new ResponseEntity<>("Invalid teamId", HttpStatus.BAD_REQUEST);
		}
		
		ObjectId userId = new ObjectId(teamMemberJson.getString("userId"));
		ObjectId teamId = new ObjectId(teamMemberJson.getString("teamId"));
		
		if(!checkIfUserExists(userId)) {
			return new ResponseEntity<>("User not found", HttpStatus.NOT_FOUND);
		}
		
		if(!checkIfTeamExists(teamId)) {
			return new ResponseEntity<>("Team not found", HttpStatus.NOT_FOUND);
		}
		
		
				
		TeamMember teamMember = new TeamMember(
			ObjectId.get(),
			userId,
			teamId,
			teamMemberJson.getString("jourDeRepos"),
			teamMemberJson.getInt("nbHeures")
		);
		
		teamMemberRepository.save(teamMember);
		
		return new ResponseEntity<>(teamMember, HttpStatus.CREATED);
	}
	
	@DeleteMapping("/teammember/{id}/delete")
	private ResponseEntity<String> deleteTeamMember(@PathVariable String id) {
		TeamMember tm = getTeamMemberById(id);
		
		if(tm == null) return new ResponseEntity<>("Team member not found", HttpStatus.NOT_FOUND);
		
		return new ResponseEntity<>("Deleted " + teamMemberRepository.deleteTeamMemberById(new ObjectId(tm.getId())) + " items", HttpStatus.OK);
	}
}