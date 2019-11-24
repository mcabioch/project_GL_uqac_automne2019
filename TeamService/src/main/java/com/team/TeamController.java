package com.team;


import javax.validation.Valid;

import org.bson.types.ObjectId;
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
	
	@GetMapping("/team/{id}")
	public Team getTeamById(@PathVariable String id) {		
		if(!ObjectId.isValid(id)) return null;
		
		ObjectId _id = new ObjectId(id);
		Team team = teamRepository.findById(_id);

		if(team == null) return null;
		
		return team;
	}
	
	@PostMapping("/create")
	private String createTeam(@Valid @RequestBody Team team) {
		team.setId(ObjectId.get());
		teamRepository.save(team);
		
		return team.getId();
	}
	
	@DeleteMapping("/team/{id}/delete")
	private ResponseEntity<String> deleteTeam(@PathVariable String id) {
		Team tm = getTeamById(id);
		
		if(tm == null) return new ResponseEntity<>("Team not found", HttpStatus.NOT_FOUND);
		
		return new ResponseEntity<>("Deleted " + teamRepository.deleteTeamById(new ObjectId(tm.getId())) + " items", HttpStatus.OK);
	}
}