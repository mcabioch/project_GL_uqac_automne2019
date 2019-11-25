const { RESTDataSource } = require('apollo-datasource-rest');

class TeamMemberAPI extends RESTDataSource {
  constructor() {
    super();
    this.baseURL = 'http://localhost:8084/';
  }

  async getAllTeamMembers() {
    return this.get('teamMembers');
  }

  async getTeamMemberByUserId(id) {
    return this.get(`/teamMember/user/${id}`);
  }

  async getTeamMembersByTeamId(teamId) {
      return this.get(`teamMember/team/${teamId}`);
  }

  async create(teamId, userId, jourDeRepos, nbHeures) {
    return this.post('create', {
        "teamId": teamId,
        "userId": userId,
        "jourDeRepos": jourDeRepos,
        "nbHeures": nbHeures
    });
  }
};

module.exports.TeamMemberAPI = TeamMemberAPI;