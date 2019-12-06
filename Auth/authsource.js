const { RESTDataSource } = require('apollo-datasource-rest');

class AuthAPI extends RESTDataSource {
  constructor() {
    super();
    this.baseURL = 'http://localhost:8080/';
  }

  async authenticate(token) {
      return this.get("auth", undefined, {
          headers: {
              'Authorization': `Basic ${token}`,
          },
      });
  }

};

module.exports.AuthAPI = AuthAPI;