package com.teammember;


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
public class TeamMemberController {
	
	@Autowired
	private TeamMemberRepository teamMemberRepository;
	
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
	
	@PostMapping("/teamMember/new")
	private String createTeamMember(@Valid @RequestBody TeamMember teamMember) {
		teamMember.setId(ObjectId.get());
		teamMemberRepository.save(teamMember);
		
		return "Team member created successfully";
	}
	
	@DeleteMapping("/teammember/{id}/delete")
	private ResponseEntity<String> deleteTeamMember(@PathVariable String id) {
		TeamMember tm = getTeamMemberById(id);
		
		if(tm == null) return new ResponseEntity<>("Team member not found", HttpStatus.NOT_FOUND);
		
		return new ResponseEntity<>("Deleted " + teamMemberRepository.deleteTeamMemberById(new ObjectId(tm.getId())) + " items", HttpStatus.OK);
	}
}