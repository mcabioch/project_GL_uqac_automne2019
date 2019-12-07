const { gql } = require('apollo-server');

const type = gql`
    type Query {
        user(id: String!): User
        users: [User]
        teamMember(userId: String!): TeamMember
        teamMembers: [TeamMember]
        team(id: String!): Team
        auth(header: String!): Auth
        register(username: String!, pass: String!, name: String!, surname: String!): User
        planning(userId: String!, date: String!): [Planning]
        createTeam(defaultHeures: Int!, nonTravail: String!, creneauDebut: String!, creneauFin: String!, chefId: String!): Team
        createTeamMember(teamId: String!, userId: String!, jourDeRepos: String!, nbHeures: Int!): TeamMember
        editUser(id: String!, username: String!, password: String!, name: String!, surname:String!): User
    }
`;

module.exports = type;