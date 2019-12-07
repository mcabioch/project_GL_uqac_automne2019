package com.planning;

import java.util.List;

import org.bson.types.ObjectId;
import org.springframework.data.mongodb.repository.MongoRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface PlanningRepository extends MongoRepository<Planning, String> {
	List<Planning> findByUserIdAndDate(ObjectId id, String date);
	List<Planning> findByUserId(ObjectId id);
}