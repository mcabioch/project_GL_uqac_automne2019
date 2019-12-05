const { RESTDataSource } = require('apollo-datasource-rest');

class PlanningAPI extends RESTDataSource {
  constructor() {
    super();
    this.baseURL = 'http://localhost:8086/';
  }

  async getPlanningByUserIdAndDate(userId, date) {
    return this.get(`/planning/${userId}/${date}`);
  }

};

module.exports.PlanningAPI = PlanningAPI;