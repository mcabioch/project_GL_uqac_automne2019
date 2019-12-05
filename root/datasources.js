const { UserAPI } = require('../User/usersource');
const { TeamMemberAPI } = require('../TeamMember/teammembersource');
const { TeamAPI } = require('../Team/teamsource');
const { AuthAPI } = require('../Auth/authsource');
const { RegisterAPI } = require('../Register/registersource');
const { PlanningAPI } = require('../Planning/planningsource');

const dataSources = { UserAPI, TeamMemberAPI, TeamAPI, AuthAPI, RegisterAPI, PlanningAPI }

module.exports = dataSources;