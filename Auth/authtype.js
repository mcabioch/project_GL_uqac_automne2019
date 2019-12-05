const { gql } = require('apollo-server');

const type = gql`
    type Auth {
        userId: String
        teamId: String
        token: String
      }
`;

module.exports = type;