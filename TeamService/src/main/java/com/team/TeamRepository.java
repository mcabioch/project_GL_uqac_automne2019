package com.team;

import org.bson.types.ObjectId;
import org.springframework.data.mongodb.repository.MongoRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface TeamRepository extends MongoRepository<Team, String> {
	Team findById(ObjectId id);
	Long deleteTeamById(ObjectId id);
}