const resolver = {
    Planning: {
        user: (parent, args, { dataSources }) => dataSources.userAPI.getUser(parent.userId)
    }
}

module.exports.resolver = resolver;