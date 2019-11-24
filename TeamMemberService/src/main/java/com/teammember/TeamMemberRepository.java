package com.teammember;

import org.bson.types.ObjectId;
import org.springframework.data.mongodb.repository.MongoRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface TeamMemberRepository extends MongoRepository<TeamMember, String> {
	TeamMember findById(ObjectId id);
	TeamMember findByUserId(ObjectId id);
	Long deleteTeamMemberById(ObjectId id);
}