// Filename: blockerSimple.h
// Created by:  drose (20Jun07)
//
////////////////////////////////////////////////////////////////////
//
// PANDA 3D SOFTWARE
// Copyright (c) Carnegie Mellon University.  All rights reserved.
//
// All use of this software is subject to the terms of the revised BSD
// license.  You should have received a copy of this license along
// with this source code in a file named "LICENSE."
//
////////////////////////////////////////////////////////////////////

#ifndef BLOCKERSIMPLE_H
#define BLOCKERSIMPLE_H

#include "pandabase.h"
#include "selectThreadImpl.h"

#ifdef THREAD_SIMPLE_IMPL

#include "pnotify.h"

////////////////////////////////////////////////////////////////////
//       Class : BlockerSimple
// Description : This is a base class for MutexSimpleImpl and
//               ConditionVarSimpleImpl.  It represents a
//               synchronization primitive that one or more threads
//               might be blocked on.
////////////////////////////////////////////////////////////////////
class EXPCL_PANDA_PIPELINE BlockerSimple {
protected:
  INLINE BlockerSimple();
  INLINE ~BlockerSimple();

protected:
  enum Flags {
    // lock_count is only used for mutexes, not condition variables.
    F_lock_count   = 0x3fffffff,
    F_has_waiters  = 0x40000000,
  };

  unsigned int _flags;

  friend class ThreadSimpleManager;
};

#include "blockerSimple.I"

#endif  // THREAD_SIMPLE_IMPL

#endif
