package com.planning;


import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.List;

import org.bson.types.ObjectId;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class PlanningController {
	
	@Autowired
	private PlanningRepository planningRepository;
	
	@GetMapping("/planning/{userId}/{stringDate}")
	public ResponseEntity<Object> getPlanningByUserIdByDate(@PathVariable String userId, @PathVariable String stringDate) {		
		if(!ObjectId.isValid(userId)) return new ResponseEntity<>("Invalid user id", HttpStatus.BAD_REQUEST);
		
		//Test if date is valid
		try {
			new SimpleDateFormat("yyyy-MM-dd").parse(stringDate);
		} catch (ParseException e) {
			e.printStackTrace();
			return new ResponseEntity<>("Invalid date", HttpStatus.BAD_REQUEST);
		}
		
		ObjectId _id = new ObjectId(userId);
		List<Planning> plannings = planningRepository.findByUserIdAndDate(_id, stringDate);

		if(plannings == null) return new ResponseEntity<>("Planning not found", HttpStatus.NOT_FOUND);
		
		return new ResponseEntity<>(plannings, HttpStatus.OK);
	}
	
	@PostMapping("/create")
	private ResponseEntity<String> createPlanning(@RequestBody Planning planning) {
		planning.setId(ObjectId.get());
		planningRepository.save(planning);
		
		return new ResponseEntity<>(planning.getId(), HttpStatus.OK);
	}
}