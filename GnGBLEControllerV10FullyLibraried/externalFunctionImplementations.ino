void extButtonEventProcess(GnG_BF_Controller_ButtonEvent* buttonEventptr)
{
  buttonEventptr->printSelf();
}

void extColorEventProcess(GnG_BF_Controller_ColorEvent* colorEventptr)
{
  colorEventptr->printSelf();
}

void extAccEventProcess(GnG_BF_Controller_AccEvent* accEventptr)
{
  accEventptr->printSelf();
}

void extMagEventProcess(GnG_BF_Controller_MagEvent* magEventptr)
{
  magEventptr->printSelf();
}

void extGyroEventProcess(GnG_BF_Controller_GyroEvent* gyroEventptr)
{
  gyroEventptr->printSelf();
}

void extQuatEventProcess(GnG_BF_Controller_QuatEvent* quatEventptr)
{
  quatEventptr->printSelf();
}
