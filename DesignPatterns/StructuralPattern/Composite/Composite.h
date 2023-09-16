//
// Created by Luca Tudor on 14.06.2023.
//

#ifndef STRUCTURALPATTERN_COMPOSITE_H
#define STRUCTURALPATTERN_COMPOSITE_H

#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <list>

/**
 * The base Component class declares common operations for both simple and
 * complex objects of a composition.
 */

class Component {
    /**
     * @var Component
     */

protected:
        std::shared_ptr<Component> parent_;

        /**
         * Optionally, the base Component can declare an interface for setting and accessing
         * a parent of the component in a tree structure. It can also provide some default
         * implementation for these methods
         */

public:
    virtual ~Component() = default;
    void setParent(std::shared_ptr<Component> parent);
    [[nodiscard]] std::shared_ptr<Component> getParent() const;

    /**
     * In some cases, it would be beneficial to define the child-management operations
     * right in the base Component class. This way, you won't need to expose any concrete
     * component classes to the client code, even during the object tree assembly. The
     * downside is that these methods will be empty for the leaf-level components.
     */

    virtual void Add(std::shared_ptr<Component> &component) {};
    virtual void Remove(std::shared_ptr<Component> &component) {};

    /**
     * You can provide a method that lets the client code figure out whether a component
     * can bear children.
     */
    [[nodiscard]] virtual bool isComposite() const;

    /**
     * The base Component may implement some default behavior or leave it to concrete
     * classes (by declaring the method containing the behavior as "abstract").
     * @return
     */
    [[nodiscard]] virtual std::string Operation() const = 0;
};

/**
 * The Leaf class represents the end objects of a composition. A leaf can't have any
 * children.
 *
 * Usually, it's the Leaf objects that do the actual work, whereas Composite objects
 * only delegate to their sub-components.
 */

class Leaf : public Component {
public:
    [[nodiscard]] std::string Operation() const override;
};

/**
 * The Composite class represents the complex components that may have children.
 * Usually, the Composite objects delegate the actual work to their children and then
 * "sum-up" the result.
 */
class Composite : public Component {
    /**
     * @var \SplObjectStorage
     */
protected:
    std::list<std::shared_ptr<Component>> children_;

public:
    /**
     * A composite object can add or remove other components (both simple or complex) to
     * or from its child list.
     */

    void Add(std::shared_ptr<Component> &component) override;
    void Remove(std::shared_ptr<Component> &component) override;
    [[nodiscard]] bool isComposite() const override;

    /**
     * The Composite executes its primary logic in a particular way. It traverses
     * recursively through all its children, collecting and summing their results.
     * Since the composite's children pass these calls to their children and so forth,
     * the whole object tree is traversed as a result.
     */

    [[nodiscard]] std::string Operation() const override;


};


#endif //STRUCTURALPATTERN_COMPOSITE_H
