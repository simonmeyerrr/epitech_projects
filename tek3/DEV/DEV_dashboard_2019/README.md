# DEV_dashboard_2019
**Developed by Simon Meyer and Arnaud Scheid**

This project was carried out as part of our third-year studies at Epitech Strasbourg.

The objective was to discover the development of a web application in javascript in 3 weeks.

We had to integrate different services with customizable widgets on a dashboard.

## Building

This project can be build using docker.

You just have to execute `./run.sh` to build and up containers.

Don't forget to add in your environment some variables such as api keys or settings.

You can see used variables for each container in `docker-compose.yml`

## Frontend

Frontend part of this project was developed with VueJS. All sources are available in `frontend`.

By default, frontend will be listening on port `:3000`.

## Backend

Backend part of this project was developed with NodeJS using express library. All sources are available in `backend`.

By default, backend will be listening on port `:8080`.

Thanks to the project architecture, it is very easy to add any services or widgets on the backend without having to change anything on the frontend.

## Database

Database part of this project is using MySQL on a mariadb container.

By default, database will be listening on port `:3306`.

Default tables are available in `database/schema.sql`. Every widget's tables are generated automatically by the backend.

# Our services and widgets

### Epitech Intranet

This service works with [Epitech's intranet](https://intra.epitech.eu). The associated widgets are:

- #### Notifications:
    
    This widget shows you your last intranet notifications.
    
    Parameters:
     - autologin: the autologin link of your account to be able to make requests
     - max_notifications: number of notifications in the widget (min: 1, max: 5, default: 5)
     - refresh: refresh interval of the widget's fronted (min: 60, max: 86400, default: 300)

### Weather

This service works with the [Open Weather Map API](https://openweathermap.org). An API key is required to make this service work. The associated widgets are:

- #### Weather:
    
    This widget shows you the actual weather of a city, anywhere in the world.
    
    Parameters:
     - city: name of the city
     - refresh: refresh interval of the widget's frontend (min: 60, max: 86400, default: 300)

- #### Forecast:
    
    This widget shows you the forecast of a city, for the next 15 days with a 3 hours period.
    
    Parameters:
     - city: name of the city
     - refresh: refresh interval of the widget's frontend (min: 60, max: 86400, default: 300)

### News

This service works with the [News API](https://newsapi.org). An API key is required to make this service work. The associated widgets are:

- #### Breaking news:
    
    This widget shows you last news with different articles link for a specific country.
    
    Parameters:
     - country: code of the country (ex: FR, US, ...)
     - refresh: refresh interval of the widget's frontend (min: 60, max: 86400, default: 300)

- #### Topic news:
    
    This widget shows you last news with different articles link for a specific topic.
    
    Parameters:
     - topic: the topic you're interested in (ex: League of legends, Bitcoin, ...)
     - refresh: refresh interval of the widget's frontend (min: 60, max: 86400, default: 300)

### Twitter

This service works with the social network [Twitter](https://twitter.com). An API key is required to make this service work. Each user have to authenticate themselves with twitter on the dashboard settings. The associated widgets are:

- #### Account:
    
    This widget shows you information about a twitter account like name, description, followers and followings.
    
    Parameters:
     - account: name of an account you want to monitor (without the `@`).
     - refresh: refresh interval of the widget's frontend (min: 60, max: 86400, default: 300)

- #### Favorites:
    
    This widget shows you last favorites of a twitter account.
    
    Parameters:
     - account: name of an account you want to monitor (without the `@`).
     - refresh: refresh interval of the widget's frontend (min: 60, max: 86400, default: 300)

# API References

Parameters and responses have to be present in request/response body as a json object.

Routes with [AUTH REQUIRED] will need an Authorization header containing a valid token. This token can be obtained on `/login` and `/register` routes.

If an error occurs, response will contain:
```
{
    error: string
}
```

- **GET** `/about.json`:
    - Description: route used to get information about services and widgets.

- **POST** `/login`:
    - Description: route used to authenticate user.
    - Parameters:
        ```
      {
            username: string
            password: string
      }
        ```
    - Response:
        ```
      {
            user_id: int
            username: string
            token: string
      }
        ```

- **POST** `/register`:
    - Description: route used to create a new user.
    - Parameters:
        ```
      {
            username: string
            password: string
      }
        ```
    - Response:
        ```
      {
            user_id: int
            username: string
            token: string
      }
        ```

- **GET** `/account` [AUTH REQUIRED]:
    - Description: get data about the authenticated user.
    - Response:
        ```
      {
            user_id: int
            username: string
            widget_count: int
            oauth: [] of {
                service: string
                status: int    (-1: unavailable, 0: not signed in, 1: signed in)
                url: string    (oauth redirect url)
            }
      }
        ```

- **POST** `/change-password` [AUTH REQUIRED]:
    - Description: update the password of the authenticated user
    - Parameters:
        ```
      {
            old_password: string
            new_password: string
      }
        ```

- **GET** `/widgets` [AUTH REQUIRED]:
    - Description: get the list of the widgets of the authenticated user
    - Response:
        ```
      [] of {
            service: string
            widget: string
            id: int
      }
        ```

- **POST** `/widget` [AUTH REQUIRED]:
    - Description: add a new widget
    - Parameters:
        ```
      {
            service: string
            widget: string
            params: object that contains parameters to build a widget
      }
        ```
    - Response:
        ```
      {
            id: int
      }
        ```

- **GET** `/widget/:service/:widget/:id` [AUTH REQUIRED]:
    - Description: get information about a specific widget
    - Response:
        ```
      {
            params: [] of {
                name: string
                type: string
                ... other informations
            }
            current: object that contains current parameters of the widget
            html: string (in html format to display it directly)
      }
        ```

- **PATCH** `/widget/:service/:widget/:id` [AUTH REQUIRED]:
    - Description: update parameters of an existing widget
    - Parameters: object that contains parameters to build a widget
    - Response:
        ```
      {
            message: string
      }
        ```

- **DELETE** `/widget/:service/:widget/:id` [AUTH REQUIRED]:
    - Description: delete a widget
    - Response:
        ```
      {
            message: string
      }
        ```

- **POST** `/oauth/:service` [AUTH REQUIRED]:
    - Description: add oauth connection
    - Parameters: element contained in the callback request of the oauth
    - Response:
        ```
      {
            message: string
      }
        ```

- **DELETE** `/oauth/:service` [AUTH REQUIRED]:
    - Description: remove oatuh connection
    - Response:
        ```
      {
            message: string
      }
        ```

# Create your own services or widgets

The architecture of our Dashboard allows you to easily add your own services or widgets with only a little code to produce.

Everything will be done automatically for you, including the creation of the tables in the database.

## Create a service

Create a folder in `backend/src/services` with the name of your service.

Create in this folder a file `index.js` with its content, don't forget to change `...` with your own content.

```javascript
// General information
const name = "..."; // name of the service with only alpha low characters
const display_name = "..."; // name of the service on frontend
const need_oauth = false; // boolean to say if this service include oauth

const widgets = [
    require('./...') // require widgets of the service in this array
];

// Exported data
module.exports = {
    name,
    display_name,
    need_oauth,
    widgets,
};
```

Then add your service in the array of required services in `backend/src/services/index.js`.

```javascript
const services = [
    require('./epitech'),
    require('./weather'),
    require('./news'),
    require('./twitter'),
    require('./...')
];
```

## Create a widget

Create a javascript file in the folder of the associated service with its content, don't forget to change `...` with your own content.

```javascript
const name = "..."; // name of the widget with only alpha low characters
const display_name = "..."; // name of the widget on frontend
const description = "..."; // description of the widget on front
/*

parameters needed to build your widget (build will be automatically)

/!\ don't use the same parameter name twice

parameters can be of type string or number

You can add :
 - a description as a string with the key description
 - a placeholder as a string or number with the key placeholder
 - a default value as string or number with the key default
 - a minimum value as number for number parameter with the key min
 - a maximum value as number for number parameter with the key max
/*
const params = [
    {
        name: "...",
        type: "..."
    },
    ...
];

function displayWidget(db, userId, dbRaw, callback) {
    // db is usefull if you have specific tables for your widget to do database query.
    // userId can be usefull with the db.
    // dbRaw contains an object with parameters of the widget
    // callback should be called with the html to display
}

// Exported data
module.exports = {
    name: name,
    display_name: display_name,
    description: description,
    params: params,
    displayWidget: displayWidget
};
```

You then just have to add you widget in the list of require of the associated service.