const { gql } = require('apollo-server');

const type = gql`
    type Planning {
        id: String
        userId: String
        user: User
        creneau: Creneau
        date: String
    }
`;

module.exports = type;