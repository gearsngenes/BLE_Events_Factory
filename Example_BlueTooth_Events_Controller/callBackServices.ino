#ifdef _Subscribe2Button
void GnGbuttonCallBack(GnGButtonEvent* buttonEventptr)
{
  buttonEventptr->printSelf();
  Serial.print("Buttion Number:::::"); Serial.println(buttonEventptr->buttonNum);
}
#endif

#ifdef _Subscribe2Color
void GnGColorCallBack(GnGColorEvent* colorEventptr)
{
  colorEventptr->printSelf();
}
#endif

#ifdef _Subscribe2Acc
void GnGAccCallBack(GnGAccEvent* accEventptr)
{
  accEventptr->printSelf();
}
#endif

#ifdef _Subscribe2Other
void GnGMagCallBack(GnGMagEvent* magEventptr)
{
  magEventptr->printSelf();
}
#endif

#ifdef _Subscribe2Other
void GnGGyroCallBack(GnGGyroEvent* gyroEventptr)
{
  gyroEventptr->printSelf();
}
#endif

#ifdef _Subscribe2Other
void GnGQuatCallBack(GnGQuatEvent* quatEventptr)
{
  quatEventptr->printSelf();
}
#endif
