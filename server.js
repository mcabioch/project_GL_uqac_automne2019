const { ApolloServer, gql } = require('apollo-server');
const { UserAPI } = require('./usersource');

const typeDefs = gql`
  type User {
    id: String!
    username: String!
    password: String!
  }

  type Query {
    user(id: String!): User
    users: [User]
  }
`;

const resolvers = {
  Query: {
    user: (root, { id }, { dataSources }) => dataSources.userAPI.getUser(id),
    users: (root, args, { dataSources }) => dataSources.userAPI.getAllUsers(),
  },
  User: {
    username: ({ username }) => username,
    password: ({ password }) => password,
  },
};

const server = new ApolloServer({
  typeDefs,
  resolvers,
  dataSources: () => ({
    userAPI: new UserAPI()
  })
});

server.listen().then(({ url }) => {
  console.log(`🚀 Server ready at ${url}`)
});