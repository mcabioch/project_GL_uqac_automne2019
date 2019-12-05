const { gql } = require('apollo-server');

const type = gql`
    type User {
        id: String
        username: String
        password: String
        name: String
        surname: String
    }
`;

module.exports = type;