const resolver = {
    Team: {
        chef: (parent, args, {dataSources }) => dataSources.teamMemberAPI.getTeamMemberByUserId(parent.chefId),
        teamMembers: (parent, args, { dataSources }) => dataSources.teamMemberAPI.getTeamMembersByTeamId(parent.id)
    }
}

module.exports.resolver = resolver;