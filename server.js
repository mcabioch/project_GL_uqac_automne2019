const { ApolloServer } = require('apollo-server');

const resolvers = require('./root/resolvers');
const typeDefs = require('./root/typedefs');
const dataSources = require('./root/datasources');

const server = new ApolloServer({
  typeDefs,
  resolvers,
  dataSources: () => ({
    userAPI: new dataSources.UserAPI(),
    teamMemberAPI: new dataSources.TeamMemberAPI(),
    teamAPI: new dataSources.TeamAPI(),
    authAPI: new dataSources.AuthAPI(),
    registerAPI: new dataSources.RegisterAPI(),
    planningAPI: new dataSources.PlanningAPI(),
  })
});

server.listen().then(({ url }) => {
  console.log(`🚀 Server ready at ${url}`)
});