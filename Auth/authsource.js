const { RESTDataSource } = require('apollo-datasource-rest');

class AuthAPI extends RESTDataSource {
  constructor() {
    super();
    this.baseURL = 'http://34.95.48.165:8080/';
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