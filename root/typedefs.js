const Auth = require('../Auth/authtype');
const User = require('../User/usertype');
const Team = require('../Team/teamtype');
const TeamMember = require('../TeamMember/teammembertype');
const Planning = require('../Planning/planningtype');
const Query = require('./querytype');

const schemaArray = [Auth, User, Team, TeamMember, Planning, Query]

module.exports = schemaArray;