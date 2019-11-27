package com.teammember;

import java.util.List;

import org.bson.types.ObjectId;
import org.springframework.data.mongodb.repository.MongoRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface TeamMemberRepository extends MongoRepository<TeamMember, String> {
	TeamMember findById(ObjectId id);
	TeamMember findByUserId(ObjectId id);
	List<TeamMember> findByTeamId(ObjectId id);
	Long deleteTeamMemberById(ObjectId id);
}