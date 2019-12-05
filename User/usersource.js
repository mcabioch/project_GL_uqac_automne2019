const { RESTDataSource } = require('apollo-datasource-rest');

class UserAPI extends RESTDataSource {
  constructor() {
    super();
    this.baseURL = 'http://34.95.48.165:8083/';
  }

  async getAllUsers() {
    return this.get('users');
  }

  async getUser(id) {
    return this.get(`users/${id}`);
  }
};

module.exports.UserAPI = UserAPI;

