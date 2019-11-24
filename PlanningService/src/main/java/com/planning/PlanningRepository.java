package com.planning;

import org.bson.types.ObjectId;
import org.springframework.data.mongodb.repository.MongoRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface PlanningRepository extends MongoRepository<Planning, String> {
	Planning findById(ObjectId id);
	Long deletePlanningById(ObjectId id);
}