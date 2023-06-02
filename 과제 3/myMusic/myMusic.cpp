#define _CRT_SECURE_NO_WARNINGS
#include "myMusic.h"
#include<string>


myMusic::myMusic() {}
myMusic::~myMusic() {}

void myMusic::setTitle(char* title) {
	strcpy(m_title, title);
}
void myMusic::setSinger(char* singer) {
	strcpy(m_singer, singer);
}
void myMusic::setAlbum(char* album) {
	strcpy(m_album, album);
}
void myMusic::setYear(int year) {
	m_year = year;
}
void myMusic::setTrackNo(int track_no) {
	m_track_no = track_no;
}
char* myMusic::getTitle() {
	return m_title;
}
char* myMusic::getSinger() {
	return m_singer;
}
char* myMusic::getAlbum() {
	return m_album;
}
int myMusic::getYear() {
	return m_year;
}
int myMusic::getTrackNo() {
	return m_track_no;
}