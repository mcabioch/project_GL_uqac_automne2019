const { merge } = require('lodash');
const Auth  = require('../Auth/authresolver');
const Team = require('../Team/teamresolver');
const TeamMember = require('../TeamMember/teammemberresolver');
const Planning = require('../Planning/planningresolver');

const resolvers = merge({
    Query: {
        user: (root, { id }, { dataSources }) => dataSources.userAPI.getUser(id),
        users: (root, args, { dataSources }) => dataSources.userAPI.getAllUsers(),
        teamMember: (root, { userId }, { dataSources }) => dataSources.teamMemberAPI.getTeamMemberByUserId(userId),
        team: (root, { id }, { dataSources }) => dataSources.teamAPI.getTeam(id),
        auth: (root, { header }, { dataSources }) => dataSources.authAPI.authenticate(header),
        register: (root, { username, pass, name, surname }, { dataSources }) => dataSources.registerAPI.register(username, pass, name, surname),
        planning: (root, {userId, date}, {dataSources}) => dataSources.planningAPI.getPlanningByUserIdAndDate(userId, date),
        createTeamMember: (root, { teamId, userId, jourDeRepos, nbHeures }, { dataSources }) => dataSources.teamMemberAPI.create(teamId, userId, jourDeRepos, nbHeures),
        createTeam: (root, { defaultHeures, nonTravail, creneauDebut, creneauFin, chefId }, { dataSources }) => dataSources.teamAPI.create(defaultHeures, nonTravail, creneauDebut, creneauFin, chefId),
        editUser: (root, { id, name, surname, nbHeures, nonTravail }, { dataSources }) => dataSources.userAPI.edit(id, name, surname).then(dataSources.teamMemberAPI.edit(id, nbHeures, nonTravail))
    }
}, Auth.resolver, Team.resolver, TeamMember.resolver, Planning.resolver)

module.exports = resolvers;