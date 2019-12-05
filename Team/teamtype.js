const { gql } = require('apollo-server');

const type = gql`
    type Team {
        id: String
        defaultHeures: String
        nonTravail: String
        creneau: Creneau
        chefId: String
        chef: TeamMember
        teamMembers: [TeamMember]
    }

    type Creneau {
        debut: String
        fin: String
    }
`;

module.exports = type;