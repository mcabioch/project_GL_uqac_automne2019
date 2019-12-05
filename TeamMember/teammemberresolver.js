const resolver = {
    TeamMember: {
        user: (parent, args, { dataSources }) => dataSources.userAPI.getUser(parent.userId),
        team: (parent, args, {dataSources }) => dataSources.teamAPI.getTeam(parent.teamId)
    }
}

module.exports.resolver = resolver;