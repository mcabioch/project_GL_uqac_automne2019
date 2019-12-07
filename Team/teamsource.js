const { RESTDataSource } = require('apollo-datasource-rest');

class TeamAPI extends RESTDataSource {
  constructor() {
    super();
    this.baseURL = 'http://localhost:8085/';
  }

  async getTeam(id) {
    return this.get(`/team/${id}`);
  }

  async create(defaultHeures, nonTravail, creneauDebut, creneauFin, chefId) {
    return this.post('create', 
      {
        "defaultHeures": defaultHeures,
        "nonTravail": nonTravail,
        "creneauDebut": creneauDebut,
        "creneauFin": creneauFin,
        "chefId": chefId
      }
    );
  }
};

module.exports.TeamAPI = TeamAPI;