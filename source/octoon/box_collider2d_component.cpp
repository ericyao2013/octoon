#include <octoon/box_collider2d_component.h>
#include <octoon/rigidbody2d_component.h>
#include <Box2D/Box2D.h>


namespace octoon
{
    OctoonImplementSubClass(BoxCollider2D, Collider2D, "BoxCollider2D")

    BoxCollider2D::BoxCollider2D() noexcept
        :is_registered(false)
    {

    }

    BoxCollider2D::~BoxCollider2D()
    {

    }

    GameComponentPtr BoxCollider2D::clone() const noexcept
    {
        return std::make_shared<BoxCollider2D>();
    }

    void BoxCollider2D::set_auto_tiling(bool is_auto_tilling) noexcept
    {
        auto_tiling = is_auto_tilling;
        on_collision_change();
    }

    bool BoxCollider2D::get_auto_tiling() const noexcept
    {
        return auto_tiling;
    }

    void BoxCollider2D::set_edge_radius(float r) noexcept
    {
        edge_radius = r;
        on_collision_change();
    }

    float BoxCollider2D::get_edge_radius() const noexcept
    {
        return edge_radius;
    }

    void BoxCollider2D::set_size(const math::Vector2& s) noexcept
    {
        size = s;
        on_collision_change();
    }

    math::Vector2 BoxCollider2D::get_size() const noexcept
    {
        return size;
    }

    void BoxCollider2D::on_collision_change() noexcept
    {
        auto rigid_body = get_component<Rigidbody2D>();
        if (!rigid_body)
            return;

        if(!is_registered)
            return;
        
        b2PolygonShape shape_def;
        shape_def.SetAsBox(size.x, size.y);
        shape_def.m_radius = edge_radius;

        b2FixtureDef fixture_def;
        fixture_def.shape = &shape_def;
        
        rigid_body->body->DestroyFixture(collider);
        collider = rigid_body->body->CreateFixture(&fixture_def);
    }

    void BoxCollider2D::on_collision_enter() noexcept
    {
        auto rigid_body = get_component<Rigidbody2D>();
        if (!rigid_body)
            return;
        
        b2PolygonShape shape_def;
        shape_def.SetAsBox(size.x, size.y);
        shape_def.m_radius = edge_radius;

        b2FixtureDef fixture_def;
        fixture_def.shape = &shape_def;
        
        collider = rigid_body->body->CreateFixture(&fixture_def);

        is_registered = true;
    }

    void BoxCollider2D::on_collision_exit() noexcept
    {
        auto rigid_body = get_component<Rigidbody2D>();
        if (!rigid_body)
            return;

        if(!is_registered)
            return;

        rigid_body->body->DestroyFixture(collider);
    }

    void BoxCollider2D::on_collision_stay() noexcept
    {

    }

    void BoxCollider2D::on_attach() except
    {
        auto rigid_body = get_component<Rigidbody2D>();
        if (!rigid_body)
            return;

        on_collision_enter();
    }

    void BoxCollider2D::on_detach() noexcept
    {
        on_collision_exit();
    }

    void BoxCollider2D::on_attach_component(const GameComponentPtr& component) except
    {
        if (component->is_a<Rigidbody2D>())
        {
            on_collision_enter();
        }
    }

    void BoxCollider2D::on_detach_component(const GameComponentPtr& component) noexcept
    {
    }
}