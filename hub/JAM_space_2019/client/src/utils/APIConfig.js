import axios from "axios";

export const API_URI = "https://space.omnirem.dev/api";

let headers = new Headers({
    "Access-Control-Allow-Origin": "*",
    'Content-Type': 'application/json',
});

function updateToken() {
    headers.Authorization = localStorage.getItem("token");
}

export default {

    login: function(username, password) {
        return axios.post(
            `${API_URI}/login`,
            {
                username: username.toUpperCase(),
                password: password
            },
            {
                headers: headers
            }
        );
    },

    register: function(username, password) {
        return axios.post(
            `${API_URI}/register`,
            {
                username: username.toUpperCase(),
                password: password
            },
            {
                headers: headers
            }
        );
    },

    createOrga: function(name) {
        updateToken();
        return axios.post(
            `${API_URI}/orga`,
            {
                name: name.toUpperCase()
            },
            {
                headers: headers
            }
        );
    },

    getOrgas: function() {
        updateToken();
        return axios.get(
            `${API_URI}/orga`,
            {
                headers: headers
            }
        );
    },

    inviteInOrga: function(name, username) {
        updateToken();
        return axios.post(
            `${API_URI}/orga/invite`,
            {
                name: name.toUpperCase(),
                username: username.toUpperCase()
            },
            {
                headers: headers
            }
        );
    },

    setOrgaActive: function(name, active) {
        updateToken();
        return axios.post(
            `${API_URI}/orga/active`,
            {
                name: name.toUpperCase(),
                active: active
            },
            {
                headers: headers
            }
        );
    },

    createPause: function(size) {
        updateToken();
        return axios.post(
            `${API_URI}/pause`,
            {
                size: size
            },
            {
                headers: headers
            }
        );
    },

    getPauses: function() {
        updateToken();
        return axios.get(
            `${API_URI}/pause`,
            {
                headers: headers
            }
        );
    },

    leaveOrga: function(name) {
        updateToken();
        return axios.delete(
            `${API_URI}/orga/${encodeURI(name.toUpperCase())}`,
            {
                headers: headers
            }
        );
    },

    getOrgaMembers: function(name) {
        updateToken();
        return axios.get(
            `${API_URI}/orga/${encodeURI(name.toUpperCase())}/members`,
            {
                headers: headers
            }
        )
    },

    getUserName: function () {
        updateToken();
        return axios.get(
            `${API_URI}/whoami`,
            {
                headers: headers
            }
        )
    }
}

