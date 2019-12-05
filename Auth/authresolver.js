const resolver = {
    Auth: {
        teamId: async (parent, args, { dataSources }) => {
          const temp = await dataSources.teamMemberAPI.getTeamMemberByUserId(parent.userId);
          return temp.teamId;
        },
      }
}

module.exports.resolver = resolver;