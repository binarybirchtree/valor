#ifndef INCLUDED_VINDICATOR_ELEMENT
#define INCLUDED_VINDICATOR_ELEMENT

namespace vindicator {

class Element {
public:
  virtual ~Element ();

  ///
  /// @return Whether or not the element is passable terrain.
  ///
  virtual bool passable () const = 0;

  ///
  /// @return Whether or not the element provides nourishment.
  ///
  virtual bool nourishing () const = 0;

  ///
  /// @return Whether or not the element contains resources.
  ///
  virtual bool bountiful () const = 0;

  ///
  /// @return Whether or not the element is adversarial.
  ///
  virtual bool adversarial () const = 0;

  ///
  /// @return ID of the owner of the element. Returns 0 if the element is unowned.
  ///
  virtual int owner () const = 0;
};

}

#endif
