const { RESTDataSource } = require('apollo-datasource-rest');

class RegisterAPI extends RESTDataSource {
  constructor() {
    super();
    this.baseURL = 'http://localhost:8082/';
  }

  async register(username, password, name, surname) {
      return this.post('create', {
          "username": username,
          "password": password,
          "name": name,
          "surname": surname
      });
  }

};

module.exports.RegisterAPI = RegisterAPI;