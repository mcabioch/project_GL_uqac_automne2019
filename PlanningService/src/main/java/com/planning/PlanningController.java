package com.planning;


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
public class PlanningController {
	
	@Autowired
	private PlanningRepository planningRepository;
	
	@GetMapping("/planning/{id}")
	public Planning getPlanningById(@PathVariable String id) {		
		if(!ObjectId.isValid(id)) return null;
		
		ObjectId _id = new ObjectId(id);
		Planning teamMember = planningRepository.findById(_id);

		if(teamMember == null) return null;
		
		return teamMember;
	}
	
	@PostMapping("/create")
	private String createPlanning(@Valid @RequestBody Planning planning) {
		planning.setId(ObjectId.get());
		planningRepository.save(planning);
		
		return planning.getId();
	}
	
	@DeleteMapping("/planning/{id}/delete")
	private ResponseEntity<String> deletePlanning(@PathVariable String id) {
		Planning tm = getPlanningById(id);
		
		if(tm == null) return new ResponseEntity<>("Planning not found", HttpStatus.NOT_FOUND);
		
		return new ResponseEntity<>("Deleted " + planningRepository.deletePlanningById(tm.getObjectId()) + " items", HttpStatus.OK);
	}
}