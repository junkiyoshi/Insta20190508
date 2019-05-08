#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetLineWidth(2);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	auto r = 100;
	auto R = 300;
	for (int i = 0; i < 2; i++) {

		for (auto v = 0; v < 360; v += 10) {

			auto u_start = ofGetFrameNum() + v * 4 + i * 180;
			for (auto u = u_start; u < u_start + 90; u += 20) {

				i == 0 ? ofSetColor(239) : ofSetColor(39);
				ofFill();

				ofBeginShape();
				ofVertex(this->make_point(R, r, u - 9.9, v - 4.9));
				ofVertex(this->make_point(R, r, u + 9.9, v - 4.9));
				ofVertex(this->make_point(R, r, u + 9.9, v + 4.9));
				ofVertex(this->make_point(R, r, u - 9.9, v + 4.9));
				ofEndShape(true);

				i == 0 ? ofSetColor(39) : ofSetColor(239);
				ofNoFill();

				ofBeginShape();
				ofVertex(this->make_point(R, r, u - 10.1, v - 5.1));
				ofVertex(this->make_point(R, r, u + 10.1, v - 5.1));
				ofVertex(this->make_point(R, r, u + 10.1, v + 5.1));
				ofVertex(this->make_point(R, r, u - 10.1, v + 5.1));
				ofEndShape(true);
			}
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
glm::vec3 ofApp::make_point(float R, float r, float u, float v) {

	// 数学デッサン教室 描いて楽しむ数学たち　P.31

	u *= DEG_TO_RAD;
	v *= DEG_TO_RAD;

	auto x = (R + r * cos(u)) * cos(v);
	auto y = (R + r * cos(u)) * sin(v);
	auto z = r * sin(u);

	return glm::vec3(x, y, z);
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}