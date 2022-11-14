from flask import Flask
from flask import json, jsonify
from flask import request, send_file
from flask_cors import CORS

from config import server_config as sconf
from config.constants import *

from controllers import db
from controllers import seats


# Creating an basic app
app = Flask(__name__)
app.config['DEBUG'] = True
cors = CORS(app)
app.config['CORS_HEADERS'] = 'Content-Type'


@app.route('/', methods=['GET'])
def home():
    """
    This function returns a message for the basic API route.
    """
    return f'<h1>Vacancy Train</h1><p>Welcome to the API.</p>'


@app.route('/login', methods=['POST'])
def login() -> json:
    """
    This function is used to login in the smart home app.

    It receives a body with the username and password.
    """
    # Generic response
    response = {
        'error': False,
        'data': None,
        'msg': None
    }

    # Login to the user
    found = db.login(request.json)

    # Validate response of the DB
    if not found:
        response['data'] = {
            'valid': False,
            'msg': 'Invalid username or password.'
        }
    else:
        response['data'] = { 'valid': True }

    return jsonify(response)


@app.route('/sign_up', methods=['POST'])
def sign_up():
    """
    This function is used to register a new user in the smart home app.
    """
    # Generic response
    response = {
        'error': False,
        'data': None,
        'msg': None
    }

    # Create user
    _id = db.create_user(request.json)

    # Validate
    if _id:
        response['data'] = { 'valid': True, 'id': _id }
    else:
        response['data'] = {
            'valid': False,
            'msg': 'User already exists.'
        }

    return jsonify(response)


@app.route('/home/get_seat_state', methods=['POST'])
def get_seat_state():
    """
    This function is used to get a light state.
    """
    # Get params
    body = request.json
    seat = body['seat']

    # Generic response
    response = {
        'error': False,
        'data': None,
        'msg': None
    }

    # Check if the pin is valid
    if (seat not in PINS['seats']):
        response['error'] = True
        response['msg'] = '{seat} not found.'
    else:
        response['data'] = {
            'state': seats.get_state(seat)
        }

    return jsonify(response)

if __name__ == '__main__':
    seats.start()
    app.run(host=sconf.HOST, port=sconf.PORT)

