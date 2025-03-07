//
// Created by chauvin on 27/05/17.
//

#ifndef CPP_INDIE_STUDIO_HEALTHBAR_HPP
#define CPP_INDIE_STUDIO_HEALTHBAR_HPP

#include <ISceneNode.h>
#include <ISceneCollisionManager.h>

namespace irr
{
  namespace scene
  {
    class HealthSceneNode : public ISceneNode
    {
     private:
      core::aabbox3d< f32 > Box;
      video::SColor BarColor;
      video::SColor BorderColor;
      video::SColor BkgColor;
      scene::ISceneCollisionManager* Coll;
      core::dimension2d<s32> m_gDim; //dimension width, height
      s32 m_bBorder;
      s32 MaxNum;
      s32 isVisible;
      s32 m_s32Percent;
     public:
      //! constructor
      HealthSceneNode( ISceneNode* parent,
		       ISceneManager* mgr,
		       s32 id,
		       scene::ISceneCollisionManager* coll,
		       s32 width = 100,
		       s32 height = 10,
		       const core::vector3df& position = core::vector3df(0,0,0),
		       video::SColor BarColor=video::SColor(150,0,200,0),
		       video::SColor BkgColor=video::SColor(150,200,0,0),
		       video::SColor BoarderColor=video::SColor(200,220,220,220) );

      //! destructor
      virtual ~HealthSceneNode();

      virtual void OnRegisterSceneNode();

      //! renders the node.
      virtual void render();

      //! returns the axis aligned bounding box of this node
      virtual const core::aabbox3d<f32>& getBoundingBox() const;

      //! returns amount of materials used by this scene node.
      virtual s32 getMaterialCount();

      //! sets progress percentage ( or health )
      virtual void setProgress( s32 s32Percent );

      //! sets the color of the progress bar
      virtual void setProgressColor(video::SColor color);

      //! sets the color of the progress bar background
      virtual void setBackgroundColor(video::SColor color);

      //! sets the color of the progress bar border
      virtual void setBorderColor(video::SColor color);
    };
  } // end namespace scene
} // end namespace irr

#endif //CPP_INDIE_STUDIO_HEALTHBAR_HPP
