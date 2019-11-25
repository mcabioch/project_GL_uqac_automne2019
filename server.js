const { ApolloServer, gql } = require('apollo-server');
const { UserAPI } = require('./usersource');
const { TeamMemberAPI } = require('./teammembersource');
const { TeamAPI } = require('./teamsource');
const { AuthAPI } = require('./authsource');
const { RegisterAPI } = require('./registersource');

const typeDefs = gql`
  type User {
    id: String
    username: String
    password: String
    name: String
    surname: String
  }

  type TeamMember {
    id: String
    userId: String
    teamId: String
    jourDeRepos: String
    nbHeures: Int
    user: User
    team: Team
  }

  type Team {
    id: String
    defaultHeures: String
    nonTravail: String
    creneau: Creaneau
    chefId: String
    chef: TeamMember
    teamMembers: [TeamMember]
  }

  type Creaneau {
    debut: String
    fin: String
  }

  type Auth {
    userId: String
    teamId: String
    token: String
  }

  type Query {
    user(id: String!): User
    users: [User]
    teamMember(userId: String!): TeamMember
    teamMembers: [TeamMember]
    team(id: String!): Team
    auth(header: String!): Auth
    register(username: String!, pass: String!, name: String!, surname: String!): User
    createTeam(defaultHeures: Int!, nonTravail: String!, creneauDebut: String!, creneauFin: String!, chefId: String!): Team
    createTeamMember(teamId: String!, userId: String!, jourDeRepos: String!, nbHeures: Int!): TeamMember
  }
`;

const resolvers = {
  Query: {
    user: (root, { id }, { dataSources }) => dataSources.userAPI.getUser(id),
    users: (root, args, { dataSources }) => dataSources.userAPI.getAllUsers(),
    teamMember: (root, { userId }, { dataSources }) => dataSources.teamMemberAPI.getTeamMemberByUserId(userId),
    team: (root, { id }, { dataSources }) => dataSources.teamAPI.getTeam(id),
    auth: (root, { header }, { dataSources }) => dataSources.authAPI.authenticate(header),
    register: (root, { username, pass, name, surname }, { dataSources }) => dataSources.registerAPI.register(username, pass, name, surname),
    createTeamMember: (root, { teamId, userId, jourDeRepos, nbHeures }, { dataSources }) => dataSources.teamMemberAPI.create(teamId, userId, jourDeRepos, nbHeures),
    createTeam: (root, { defaultHeures, nonTravail, creneauDebut, creneauFin, chefId }, { dataSources }) => dataSources.teamAPI.create(defaultHeures, nonTravail, creneauDebut, creneauFin, chefId)
  },
  TeamMember: {
    user: (parent, args, { dataSources }) => dataSources.userAPI.getUser(parent.userId),
    team: (parent, args, {dataSources }) => dataSources.teamAPI.getTeam(parent.teamId)
  },
  Team: {
    chef: (parent, args, {dataSources }) => dataSources.teamMemberAPI.getTeamMemberByUserId(parent.chefId),
    teamMembers: (parent, args, { dataSources }) => dataSources.teamMemberAPI.getTeamMembersByTeamId(parent.id),
  },
  Auth: {
    teamId: async (parent, args, { dataSources }) => {
      const temp = await dataSources.teamMemberAPI.getTeamMemberByUserId(parent.userId);
      return temp.teamId;
    },
  }
};

const server = new ApolloServer({
  typeDefs,
  resolvers,
  dataSources: () => ({
    userAPI: new UserAPI(),
    teamMemberAPI: new TeamMemberAPI(),
    teamAPI: new TeamAPI(),
    authAPI: new AuthAPI(),
    registerAPI: new RegisterAPI(),
  })
});

server.listen().then(({ url }) => {
  console.log(`🚀 Server ready at ${url}`)
});