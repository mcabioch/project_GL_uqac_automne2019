const { gql } = require('apollo-server');

const type = gql`
    type TeamMember {
        id: String
        userId: String
        teamId: String
        jourDeRepos: String
        nbHeures: Int
        user: User
        team: Team
  }
`;

module.exports = type;