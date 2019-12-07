const { RESTDataSource } = require('apollo-datasource-rest');

class UserAPI extends RESTDataSource {
  constructor() {
    super();
    this.baseURL = 'http://localhost:8083/';
  }

  async getAllUsers() {
    return this.get('users');
  }

  async getUser(id) {
    return this.get(`users/${id}`);
  }

  async edit(id, username, password, name, surname) {
    return this.patch(`user/${id}/edit`,
      {
        "username" : username,
        "password" : password,
        "name" : name,
        "surname" : surname
      }
    );
  }
};

module.exports.UserAPI = UserAPI;

